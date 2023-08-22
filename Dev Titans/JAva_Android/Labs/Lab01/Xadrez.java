import java.util.Scanner;

public class Xadrez {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lê a quantidade de linhas do usuário
        int linhas = scanner.nextInt();
        scanner.close();

        // Loop para imprimir o padrão
        for (int i = 1; i <= linhas; i++) {
            // Se a linha for par, começa com um espaço em branco
            if (i % 2 == 0) {
                System.out.print(" ");
            }
            for (int j = 1; j <= linhas; j++) {
                System.out.print("* ");
            }
            System.out.println(); // Pula para a próxima linha após imprimir a linha atual
        }
    }
}
