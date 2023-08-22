import java.util.Scanner;

public class ContaEnergia {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lê o consumo de energia em kWh
        int consumo = scanner.nextInt();

        // Lê o tipo de instalação (R para residências, I para indústrias, e C para comércios)
        char tipo = scanner.next().charAt(0);
        scanner.close();

        // Calcula o preço devido de acordo com o tipo de instalação e faixa de consumo
        double preco;
        if (tipo == 'R' || tipo == 'r') {
            if (consumo <= 500) {
                preco = consumo * 0.40;
            } else {
                preco = consumo * 0.65;
            }
        } else if (tipo == 'C' || tipo == 'c') {
            if (consumo <= 1000) {
                preco = consumo * 0.55;
            } else {
                preco = consumo * 0.60;
            }
        } else if (tipo == 'I' || tipo == 'i') {
            if (consumo <= 5000) {
                preco = consumo * 0.55;
            } else {
                preco = consumo * 0.60;
            }
        } else {
            preco = -1.00; // Valor inválido de tipo de instalação
        }

        // Imprime o preço devido com duas casas decimais
        if (preco >= 0) {
            System.out.printf("%.2f\n", preco);
        } else {
            System.out.println("-1.00");
        }
    }
}
