# Blink

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

<h2>Workarounds</h2>

- Error of GPIO in use (etc) was fixed by by running `azsphere device recover`
(probably a better way -> but works for now)



