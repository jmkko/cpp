#!/bin/bash

# Couleurs pour l'affichage
GREEN="\033[0;32m"
NC="\033[0m"

echo -e "${GREEN}📦 Poussée des submodules...${NC}"

# Liste des modules à parcourir (tu peux l’adapter)
for module in cpp0{0..9}; do
    if [ -d "$module" ]; then
        echo -e "${GREEN}→ Traitement de $module${NC}"
        cd "$module"
        
        # Vérifie s'il y a des modifications
        if [[ -n $(git status --porcelain) ]]; then
            git add .
            git commit -m "Mise à jour automatique dans $module"
            git push
        else
            echo "Aucun changement dans $module"
        fi

        cd ..
    fi
done

echo -e "${GREEN}🔁 Mise à jour du repo principal...${NC}"

# On revient à la racine du projet
cd "$(dirname "$0")"

git add .
git commit -m "Mise à jour des submodules (auto)"
git push

echo -e "${GREEN}✅ Tout est à jour !${NC}"

