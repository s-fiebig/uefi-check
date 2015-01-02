#include <stdio.h>
#include <Windows.h>
#include "wincommon.h"

#ifdef UNICODE
#define ___T(str) GetWChar(str)
#else
#define ___T(str) str
#endif

void check_uefi();


// Determine if running UEFI. If no -> then exit
void check_uefi() {

	// Only since Windows 8
	//FIRMWARE_TYPE fwtype;
	//GetFirmwareType(&fwtype);
	//if (fwtype != FirmwareTypeUefi) {
	//	printf("You are not running UEFI!\n");
	//	exit(-1);
	//}

	// Not needed for read access
	//ObtainPrivileges(SE_SYSTEM_ENVIRONMENT_NAME);

	// Perform check if UEFI variables are present.
	// If not, we get ERROR_INVALID_FUNCTION on this.
	// If yes, we get ERROR_NOACCESS because we are accessing not-existing variable.
	// Any other errors are unexpected.

	if (GetFirmwareEnvironmentVariable(___T(""), ___T("{00000000-0000-0000-0000-000000000000}"), NULL, 0) == 0) {
		if (GetLastError() == ERROR_INVALID_FUNCTION) {
			printf("Cannot access UEFI (are you running BIOS?)\n");
			exit(-1);
		}
		
		else if (GetLastError() == ERROR_NOACCESS) {
			// Expected
			printf("UEFI is available.\n");
		}
		else {
			PrintError(GetLastError());
			exit(GetLastError());
		}
	}
}

int main(int argc, char *argv[]) {
	check_uefi();
}