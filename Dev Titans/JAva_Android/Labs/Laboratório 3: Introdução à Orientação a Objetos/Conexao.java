public class Conexao {
    String tipoPorta;
    int idProtocolo;
    int taxaTransmissao; // em bytes por segundo (Bps)

    // Construtor padrão
    public Conexao() {
    }

    // Construtor com parâmetros para definir os atributos diretamente
    public Conexao(String tipoPorta, int idProtocolo, int taxaTransmissao) {
        this.tipoPorta = tipoPorta;
        this.idProtocolo = idProtocolo;
        this.taxaTransmissao = taxaTransmissao;
    }

    // Métodos getters e setters
    public String getTipoPorta() {
        return tipoPorta;
    }

    public void setTipoPorta(String tipoPorta) {
        this.tipoPorta = tipoPorta;
    }

    public int getIdProtocolo() {
        return idProtocolo;
    }

    public void setIdProtocolo(int idProtocolo) {
        this.idProtocolo = idProtocolo;
    }

    public int getTaxaTransmissao() {
        return taxaTransmissao;
    }

    public void setTaxaTransmissao(int taxaTransmissao) {
        this.taxaTransmissao = taxaTransmissao;
    }

     //Método para retornar a taxa de transmissão em MBps (Megabytes por segundo)
    public double getTaxaMBps() {
        return taxaTransmissao / 1024.0;
    }

    // Método para retornar o protocolo como String de acordo com o atributo idProtocolo
    public String getProtocoloString() {
        switch (idProtocolo) {
            case 1:
                return "Rotoscope";
            case 2:
                return "Acustico";
            case 3:
                return "Radio";
            default:
                return "Outros";
        }
    }

    // Método para retornar a descrição da conexão
    public String getDescricao() {
        return "Conexao: tipoPorta=" + tipoPorta + ", protocolo=" + getProtocoloString() +
                ", taxaTransmissao=" + getTaxaMBps()+ "MBps.";
    }
}
