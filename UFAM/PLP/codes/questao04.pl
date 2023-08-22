open(my $file, "<", "alunos_IFPB.csv") or die "Não foi possível abrir o arquivo: $!";

while (my $line = <$file>) {
    chomp $line;

    my @campos = split(",", $line);
    my $matricula = $campos[1];
    my $cidade = $campos[4];

    if ($cidade =~ /JOÃO PESSOA/) {
        print "Matricula: $matricula\n";
    }
}

close($file);
