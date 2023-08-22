arquivo = open("alunos_IFPB.csv", "r")

contagens = {}

for linha in arquivo:
    campos = linha.split(",")
    situacao = campos[5].strip()
    
    if situacao in contagens:
        contagens[situacao]+=1
    else:
        contagens[situacao] = 1
        
arquivo.close()
#print(contagens)

for situacao, quantidade in contagens.items():
    print(f"{situacao}: {quantidade}")

