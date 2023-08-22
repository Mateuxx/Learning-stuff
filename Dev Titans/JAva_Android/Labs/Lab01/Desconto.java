import java.util.Scanner;

public class Desconto {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lê o preço sem desconto da compra
        float precoSemDesconto = scanner.nextFloat();
        scanner.close();

        // Aplica o desconto de 5% se o valor for R$200 ou mais
        float precoComDesconto = precoSemDesconto;
        if (precoSemDesconto >= 200.0f) {
            precoComDesconto *= 0.95f; // Desconto de 5%
        }

        // Imprime o valor a ser pago pelo cliente com duas casas decimais
        System.out.printf("%.2f\n", precoComDesconto);
    }
}
