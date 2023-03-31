# Git Large File Storage

To associate a file type in your repository with Git LFS, enter git lfs track followed by the name of the file extension you want to automatically upload to Git LFS.
```
$ git lfs track "*.psd"
> Tracking "*.psd"
```

> [!NOTE]
> - #### Make sure .gitattributes is tracked:
> ```git add .gitattributes``` 
> - Relying on a global .gitattributes file associated with Git LFS may cause conflicts when contributing to other Git projects.
> - Including the .gitattributes file in the repository allows people creating forks or fresh clones to more easily collaborate using Git LFS.
> - Including the .gitattributes file in the repository allows Git LFS objects to optionally be included in ZIP file and tarball archives.

List which files are currently tracked by LFS:  
```git lfs ls-files```

Convert back to regular Git storage  
```git lfs migrate export --everything --include="*.bin,*.psd"```