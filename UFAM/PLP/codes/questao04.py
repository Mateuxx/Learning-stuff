file = open("alunos_IFPB.csv","r") 

line = file.readline() 

while line:

    
    campos = line.split(",")
    #print(campos)
    matricula=campos[1]
    cidade = campos[4]
 
    if"JOÃO PESSOA" in cidade:
        print("Matricula:", matricula) 

    line  = file.readline()

file.close( )