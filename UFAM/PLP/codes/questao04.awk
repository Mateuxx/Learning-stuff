BEGIN {
    FS = ","
}

{
    matricula = $2
    cidade = $5

    if (cidade ~ /JOÃO PESSOA/) {
        print "Matricula:", matricula
    }
}
