arquivo = open("alunos_IFPB.csv", "r")

for linha in arquivo:
   
    campos = linha.split(",")
    #print(campos)
   
    matricula = campos[1]
    nome = campos[0]

    
    palavras = nome.split()
    print(palavras)

    for palavra in palavras: 
        if palavra.upper() == "DA":
            print("Matricula:",matricula)
            print("Nome", nome,"\n")
        if palavra.upper() == "DE":
            print("Matricula:",matricula)
            print("Nome", nome,"\n")
        if palavra.upper() == "DO":
            print("Matricula:",matricula)
            print("Nome", nome,"\n")

arquivo.close()