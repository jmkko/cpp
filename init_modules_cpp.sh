#!/bin/bash

GITHUB_USER="jmkko"

START=1
END=9

for i in $(seq -f "%02g" $START $END); do
  MODULE="cpp$i"
  echo "🔧 Traitement de $MODULE..."

  # Vérifie si le dossier existe déjà
  if [ -d "$MODULE" ]; then
    echo "⚠️ Le dossier $MODULE existe déjà. On saute."
    continue
  fi

  # 1. Création dossier, init Git local
  mkdir "$MODULE"
  cd "$MODULE"
  git init
  echo "# $MODULE" > README.md
  git add README.md
  git commit -m "Initial commit for $MODULE"
  git branch -M main
  git remote add origin git@github.com:$GITHUB_USER/$MODULE.git
  git push -u origin main
  cd ..

  # 2. Ajouter en tant que submodule
  git submodule add git@github.com:$GITHUB_USER/$MODULE.git $MODULE
done

# 3. Commit dans le repo principal
git add .gitmodules cpp*/
git commit -m "Ajout des submodules cpp01 à cpp09"
git push

echo "✅ Tous les modules sont initialisés et ajoutés comme submodules."

