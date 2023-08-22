import java.util.Scanner;

public class PorcentagemAcerto {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lê as respostas do candidato e o gabarito
        int[] respostas = lerVetor(scanner);
        int[] gabarito = lerVetor(scanner);
        scanner.close();

        // Calcula a porcentagem de acerto
        double porcentagem = calcularPorcentagemAcerto(respostas, gabarito);

        // Imprime a porcentagem de acerto com duas casas decimais
        System.out.printf("%.2f\n", porcentagem);
    }

    public static int[] lerVetor(Scanner scanner) {
        int tamanho = 0;
        int elemento = 0;
        int[] vetor = new int[10]; // Tamanho máximo de 10 elementos, pode ser ajustado conforme a necessidade

        while (elemento != -1) {
            elemento = scanner.nextInt();
            if (elemento != -1) {
                if (tamanho >= vetor.length) {
                    // Aumenta o tamanho do vetor caso seja necessário
                    int[] novoVetor = new int[vetor.length * 2];
                    System.arraycopy(vetor, 0, novoVetor, 0, vetor.length);
                    vetor = novoVetor;
                }
                vetor[tamanho] = elemento;
                tamanho++;
            }
        }

        // Redimensiona o vetor para o tamanho real
        int[] resultado = new int[tamanho];
        System.arraycopy(vetor, 0, resultado, 0, tamanho);
        return resultado;
    }

    public static double calcularPorcentagemAcerto(int[] respostas, int[] gabarito) {
        int acertos = 0;
        for (int i = 0; i < respostas.length; i++) {
            if (respostas[i] == gabarito[i]) {
                acertos++;
            }
        }

        return (double) acertos / respostas.length * 100.0;
    }
}
