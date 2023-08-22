BEGIN {
    FS = ","
}

{
    matricula = $2
    nome = $1

    split(nome, palavras, " ")

    for (i = 1; i <= length(palavras); i++) {
        palavra = palavras[i]
        if (toupper(palavra) == "DA" || toupper(palavra) == "DE" || toupper(palavra) == "DO") {
            print "Matricula:", matricula
            print "Nome:", nome
            print ""
        }
    }
}