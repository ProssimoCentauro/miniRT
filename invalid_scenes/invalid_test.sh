#!/bin/bash

#RUN THIS SCRIPT WHILE IN THE invalid_scenes FOLDER

# ANSI Colors
YELLOW='\033[1;33m'
NC='\033[0m' # Nessun colore

# Executable Path
EXEC="./minirt"

# Scenes Folder
SCENES_DIR="invalid_scenes"

cd ..

#Loop all .rt files
for FILE in $SCENES_DIR/*.rt; do
    echo -e "${YELLOW}== testing file $(basename "$FILE") ==${NC}"
    $EXEC "$FILE"
    echo -e "${YELLOW}=============================${NC}\n"
done

