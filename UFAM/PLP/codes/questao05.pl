open(my $arquivo, "<", "alunos_IFPB.csv") or die "Não foi possível abrir o arquivo: $!";

my %contagens;

while (my $linha = <$arquivo>) {
    chomp $linha;
    my @campos = split(",", $linha);
    my $situacao = $campos[5];
    $situacao =~ s/^\s+|\s+$//g;  # Remover espaços em branco no início e no final
    
    if (exists $contagens{$situacao}) {
        $contagens{$situacao}++;
    } else {
        $contagens{$situacao} = 1;
    }
}

close($arquivo);

foreach my $situacao (keys %contagens) {
    my $quantidade = $contagens{$situacao};
    print "$situacao: $quantidade\n";
}
