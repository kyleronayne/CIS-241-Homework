#!/bin/bash
echo "Creating new project repository..."
mkdir $1
cd $1
git init
mkdir bin include lib share man info
touch README.md
echo $1 >> README.md
touch .gitignore
git add .
git commit -m "Create initial structure."
echo "New project repository created!"
