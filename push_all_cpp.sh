#!/bin/bash

# Couleurs pour l'affichage
GREEN="\033[0;32m"
NC="\033[0m"

echo -e "${GREEN}📦 Poussée des submodules...${NC}"

# Liste des modules à parcourir (tu peux l’adapter)
for module in cpp0{0..9}; do
    if [ -d "$module" ]; then
        echo -e "${GREEN}→ Traitement de $module${NC}"
        cd "$module" || continue

        # Nettoyage dans tous les sous-dossiers de type exXX/
        for exdir in ex*/; do
            if [ -d "$exdir" ] && [ -f "$exdir/Makefile" ]; then
                echo -e "${GREEN}🧹 make fclean dans $module/$exdir${NC}"
                make -C "$exdir" fclean > /dev/null 2>&1
            fi
        done
        BRANCH=$(git symbolic-ref --short -q HEAD)

        if [ -z "$BRANCH" ]; then
          echo "🔧 HEAD détachée détectée, tentative de rattachement à origin/main"
          git checkout -B main origin/main
          BRANCH="main"
        fi
        # Vérifie s'il y a des modifications
        if [[ -n $(git status --porcelain) ]]; then
            git add .
            git commit -m "Mise à jour automatique dans $module"
            git push origin "$BRANCH"
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
echo -e $USER

