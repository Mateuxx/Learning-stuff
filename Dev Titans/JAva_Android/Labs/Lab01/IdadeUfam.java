import java.util.Scanner;

public class IdadeUfam {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lê o ano atual do teclado
        int anoAtual = scanner.nextInt();
        scanner.close();

        // Calcula a idade da UFAM
        int anoFundacaoUfam = 1909;
        int idadeUfam = anoAtual - anoFundacaoUfam;

        // Imprime a mensagem com a idade da UFAM
        System.out.println("A UFAM tem " + idadeUfam + " anos de fundacao");
    }
}
