
import java.util.LinkedList;

public class GoogleMain {
    public static void main(String[] args) {
        // Criando uma instância da classe ListaInvertida
        ListaInvertida listaInvertida = new ListaInvertida();

        // Inserindo palavras e documentos
        listaInvertida.insere("force", "document1.txt");
        listaInvertida.insere("force", "document2.txt");
        listaInvertida.insere("force", "document3.txt");
        listaInvertida.insere("always", "document1.txt");
        listaInvertida.insere("one", "document3.txt");
        listaInvertida.insere("is", "document2.txt");
        listaInvertida.insere("is", "document3.txt");
        listaInvertida.insere("be", "document1.txt");
        listaInvertida.insere("will", "document1.txt");
        listaInvertida.insere("you", "document1.txt");
        listaInvertida.insere("you", "document2.txt");
        listaInvertida.insere("the", "document1.txt");
        listaInvertida.insere("the", "document2.txt");
        listaInvertida.insere("the", "document3.txt");
        listaInvertida.insere("remember", "document1.txt");
        listaInvertida.insere("this", "document3.txt");
        listaInvertida.insere("strong", "document2.txt");
        listaInvertida.insere("strong", "document3.txt");
        listaInvertida.insere("with", "document1.txt");
        listaInvertida.insere("with", "document2.txt");
        listaInvertida.insere("with", "document3.txt");

        // Testando o método busca
        LinkedList<String> documentos = listaInvertida.busca("strong");
        System.out.println("Documentos que contêm a palavra 'strong': " + documentos);

        documentos = listaInvertida.busca("you");
        System.out.println("Documentos que contêm a palavra 'you': " + documentos);

        documentos = listaInvertida.busca("remember");
        System.out.println("Documentos que contêm a palavra 'remember': " + documentos);

        // Testando o método toString
        System.out.println("Lista Invertida: " + listaInvertida.toString());
    }
}
