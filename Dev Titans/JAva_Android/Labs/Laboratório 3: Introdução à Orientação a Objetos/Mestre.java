public class Mestre {
    String nome;
    int anoNascimento;
    String afiliacao;
    String posto;

    // Construtor padrão
    public Mestre() {
    }

    // Construtor com parâmetros para definir os atributos diretamente
    public Mestre(String nome, int anoNascimento, String afiliacao, String posto) {
        this.nome = nome;
        this.anoNascimento = anoNascimento;
        this.afiliacao = afiliacao;
        this.posto = posto;
    }

    // Métodos getters e setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getAnoNascimento() {
        return anoNascimento;
    }

    public void setAnoNascimento(int anoNascimento) {
        this.anoNascimento = anoNascimento;
    }

    public String getAfiliacao() {
        return afiliacao;
    }

    public void setAfiliacao(String afiliacao) {
        this.afiliacao = afiliacao;
    }

    public String getPosto() {
        return posto;
    }

    public void setPosto(String posto) {
        this.posto = posto;
    }

    // Método para calcular a idade do mestre em relação ao ano de referência
    public int getIdade(int anoReferencia) {
        return anoReferencia - this.anoNascimento;
    }

    // Método para retornar a descrição completa do mestre
    public String getDescricao() {
        return "Mestre: nome=" + nome + ", anoNascimento=" + getAnoNascimentoString() +
                ", afiliacao=" + afiliacao + ", posto=" + posto + ", possuiForca=" + possuiForca() + ".";
    }

    // Método para retornar o ano de nascimento do mestre seguido da sigla ABY (anoNascimento negativo) ou DBY (anoNascimento positivo)
    public String getAnoNascimentoString() {
        return (anoNascimento < 0 ? Math.abs(anoNascimento) + "ABY" : anoNascimento + "DBY");
    }

    // Método para verificar se o mestre possui a Força
    public boolean possuiForca() {
        return posto.equals("Jedi") || posto.equals("Sith");
    }
}
