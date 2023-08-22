public class AstromechMain {
    public static void main(String[] args) {
        // Criando objetos da classe Mestre
        Mestre mestre1 = new Mestre("Luke Skywalker", 19, "Alianca para Restauracao da Republica", "Jedi");
        Mestre mestre2 = new Mestre("Darth Vader", 41, "Imperio Galatico", "Sith");

        // Criando objetos da classe Sensor
        Sensor sensor1 = new Sensor("Azul", 512.0, 240);
        Sensor sensor2 = new Sensor("Verde", 1024.0, 120);

        // Criando objetos da classe Conexao
        Conexao conexao1 = new Conexao("SCOMP Link", 1, 4000);
        Conexao conexao2 = new Conexao("Data Bus", 2, 2048);

        // Criando objetos da classe Astromech
        Astromech astromech1 = new Astromech("R2-D2", mestre1, sensor1, conexao1);
        Astromech astromech2 = new Astromech("BB-8", mestre2, sensor2, conexao2);

        // Imprimindo descrições dos objetos criados
        System.out.println(astromech1.getDescricao());
        System.out.println(astromech2.getDescricao());
    }
}
