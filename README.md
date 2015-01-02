uefi-check
==========

Checks for UEFI or legacy bios using the method described here: http://msdn.microsoft.com/en-us/library/windows/desktop/ms724325.aspx

The API descriptions are misleading as the kernel-mode function ExGetFirmwareEnvironmentVariable is only available since Windows 8 but GetFirmwareEnvironmentVariable since Windows XP SP1.

Code templates from: https://github.com/black3r/efireboot