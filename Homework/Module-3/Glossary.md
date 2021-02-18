**ls** - Outputs the files in the current directory; Stands for list segments.
```
ls Desktop
```
**touch** - Creates a specified file
```
touch ronayne.txt
```
**ls -la** - Outputs the files in the current directory, including the hidden files
```
ls -la
```
**ls -l** - Shows the files in the current directory in long form.
```
ls -l
```
**ls -R** - Recursively shows the files in the current directory.
```
ls -R
```
**pwd** - Outputs the present working directory.
```
pwd
```
**cd** - Moves the user to the specified directory.
```
cd CIS_241_Ronayne
```
**man** - Outputs the manual for the specified command.
```
man chmod
```
**echo $HOSTNAME** - Outputs the hostname/server name.
```
echo $HOSTNAME
```
**echo $MACHTYPE** - Outputs what type of machine the kernel is on.
```
echo $MACHTYPE
```
**echo $PS1** - Outputs the kernel prompt in the format user@host working directory.
```
echo $PS1
```
**stat** - Outputs the specified file’s statistics.
```
stat Glossary.md
```
**rm** - Deleted the specified file.
```
rm ronayne.txt
```
**rm -d** - Deletes the specified directory.
```
rm -d Classwork
```
**cp** - Copies an existing file. cp <existing file name> <new file name>.
```
cp Homework.txt StuffIDontLikeToDo.txt
```
**cp -R** - Copies an existing directory. cp <exiting directory name> <new file name>.
```
cp Desktop DesktopCopy
```
**mv** - Moves a file to specifed directory. mv <file name> <destination directory>
```
mv Module-3-Assignment.txt Homework
```
**chown** - Changes the ownership of a file. chown <user> <file name> or chown <user:group> <file name>
```
chown woodriir ronayne.txt
chown woodriir:CIS_241_Students Assignments-To-Do.txt
```  
**tr** - Translates text. cat <file name> | tr
```
cat TheWhale.txt | tr
``` 
**sort** - Sorts words in the specified file. cat  <file name> | sort
```
cat TheWhale.txt | sort
```
**chmod** - Changes the permissions for a file. chmod <ugoa><+-><rwx> <file name>. Component #1 specifies who you are changing permissions for (e.g. user owner, others, or all three. Component #2 specifies how you want change the permissions (e.g. add or delete). Component #3 specifies which permission you want to change (e.g. read, write, or execute).
```
chmod ugo+r foo
```
**df** - Displays information related to file systems about total space and available space.
```
df Glossary.md
```
**du** - Short for disk usage and is used to estimate file space usage and can be used to track the files and directories which are consuming excessive amounts of space on hard disk drives.
```
du TheWhale.txt
```
**more** - Shows text files by displaying them one page at a time if they are large enough.
```
more TheWhale.txt
```
**less** - Shows text files by displaying them one page at a time if they are large enough and give the user the ability to navigate both forwards and backwards.
```
less TheWhale.txt
```
**head** - Displays the top n number of lines in a file. head -n <number> <file name>.
```
head -n 3 ronayne.txt
```
**tail** - Displays the bottom n number of lines in a file. tail -n <number> <file name>.
```
tail -n 100 TheWhale.txt
```

















