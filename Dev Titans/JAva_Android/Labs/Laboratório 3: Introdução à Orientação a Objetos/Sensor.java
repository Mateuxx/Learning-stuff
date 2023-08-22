public class Sensor {
    String cor;
    double resolucao;
    int framesPorSegundo;

    // Construtor padrão
    public Sensor() {
    }

    // Construtor com parâmetros para definir os atributos diretamente
    public Sensor(String cor, double resolucao, int framesPorSegundo) {
        this.cor = cor;
        this.resolucao = resolucao;
        this.framesPorSegundo = framesPorSegundo;
    }

    // Métodos getters e setters
    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    public double getResolucao() {
        return resolucao;
    }

    public void setResolucao(double resolucao) {
        this.resolucao = resolucao;
    }

    public int getFramesPorSegundo() {
        return framesPorSegundo;
    }

    public void setFramesPorSegundo(int framesPorSegundo) {
        this.framesPorSegundo = framesPorSegundo;
    }

    // Método para calcular a multiplicação da resolução pela quantidade de frames por segundo
    public double getMPixelsPorSegundo() {
        return resolucao * framesPorSegundo;
    }

    // Método para retornar a descrição do sensor
    public String getDescricao() {
        return "Sensor: cor=" + cor + ", resolucao=" + resolucao + "Mp, framesPorSegundo=" +
                framesPorSegundo + "fps, mPixelsPorSegundo=" + getMPixelsPorSegundo() + "Mpps.";
    }
}
