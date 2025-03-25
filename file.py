import os

output_file = "toto.txt"

ban_list = [
    ".git",
    ".vscode",
    ".gitignore",
    "file.py"
]

def parcourir_dossier(dossier, outfile):
    for item in os.listdir(dossier):
        chemin_complet = os.path.join(dossier, item)
        if item in ban_list:
            continue
        if os.path.isfile(chemin_complet):
            with open(chemin_complet, "r") as infile:
                outfile.write(f"Contenu de {chemin_complet} :\n")
                outfile.write(infile.read())
                outfile.write("\n\n")
        elif os.path.isdir(chemin_complet):
            parcourir_dossier(chemin_complet, outfile)
with open(output_file, "w") as outfile:
    parcourir_dossier(".", outfile)
print(f"Le contenu des fichiers a été redirigé vers {output_file}")
