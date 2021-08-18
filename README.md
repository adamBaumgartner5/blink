# blink

<h2>Clone repository steps </h2>

1. Pull repo with `git clone .git`
2. Delete file /out/CMakeCache.txt
3. Run `CMake: Clean Rebuild` from command pallet
4. Build should be successful, and ready to start making changes to main.c
5. Flash data by going to 'Project/out/ARM-Debug' and using `azsphere device sideload deploy --image-package filename.imagepackage`

<h2>New Project Notes </h2>

- For `Azure Sphere: Generate New Project` use  with `Blink` because `HL Core Blank` is missing `HardwareDefinitions`. 

- Be sure `.gitignore` from `Azure Sphere: Generate New Project` has been removed.
The `/out/` folder holds important information

- `git init` in the folder created by VS Code works great. No need for additional folder layer

<h2>Removing sideloaded code</h2>

- If you sideload code, you need to be sure the code already on the device does not use the same resources.
- use `azsphere device sideload delete --component-id ######`
- Get component-id from `azsphere device image list-installed`

<h2>Blink without using nanosleep</h2>
![debugger_view](https://imgur.com/a/W3HToRg)


