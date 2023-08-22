open(my $arquivo, "<", "alunos_IFPB.csv") or die "Não foi possível abrir o arquivo: $!";

while (my $linha = <$arquivo>) {
    chomp $linha;
    my @campos = split(",", $linha);
    
    my $matricula = $campos[1];
    my $nome = $campos[0];

    my @palavras = split(" ", $nome);

    foreach my $palavra (@palavras) {
        if (uc($palavra) eq "DA" ) {
            print "Matricula: $matricula\n";
            print "Nome: $nome\n\n";
            last;  # Para sair do loop após encontrar uma correspondência
        }
        if  (uc($palavra) eq "DE") {
            print "Matricula: $matricula\n";
            print "Nome: $nome\n\n";
            last;
        }
        if  (uc($palavra) eq "DO") {
            print "Matricula: $matricula\n";
            print "Nome: $nome\n\n";
            last;
        }
    }
}

close($arquivo);
