SELECT nom, prenom
FROM fiche_personne
WHERE prenom like '%-%' or nom like '%-%'
ORDER BY nom ASC, prenom ASC;