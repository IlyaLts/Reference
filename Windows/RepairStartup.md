```
diskpart
list disk
select disk (x)
list partition
select partition (x)
shrink desired=500
create partition efi size=500
format quick fs=fat32 label="system"
create partition msr size=128
list vol
select volume (x)
assign letter=x
bootrec /rebuildbcd
```

more info on https://support.microsoft.com/en-us/topic/use-bootrec-exe-in-the-windows-re-to-troubleshoot-startup-issues-902ebb04-daa3-4f90-579f-0fbf51f7dd5d