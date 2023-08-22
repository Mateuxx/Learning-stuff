public class Astromech {
    String modelo;
    Mestre mestre;
    Sensor sensor;
    Conexao conexao;

    // Construtor padrão
    public Astromech() {
    }

    // Construtor com parâmetros para definir os atributos diretamente
    public Astromech(String modelo, Mestre mestre, Sensor sensor, Conexao conexao) {
        this.modelo = modelo;
        this.mestre = mestre;
        this.sensor = sensor;
        this.conexao = conexao;
    }

    // Métodos getters e setters
    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public Mestre getMestre() {
        return mestre;
    }

    public void setMestre(Mestre mestre) {
        this.mestre = mestre;
    }

    public Sensor getSensor() {
        return sensor;
    }

    public void setSensor(Sensor sensor) {
        this.sensor = sensor;
    }

    public Conexao getConexao() {
        return conexao;
    }

    public void setConexao(Conexao conexao) {
        this.conexao = conexao;
    }

    // Método para retornar a descrição completa do droid Astromech
    public String getDescricao() {
        return "Astromech modelo " + modelo + ". " + mestre.getDescricao() + " " + sensor.getDescricao() + " " + conexao.getDescricao();
    }
}
