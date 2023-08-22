import java.util.*;

public class ListaInvertida {
	private Hashtable<String, LinkedList<String>> tabela;
	
	public ListaInvertida () {
		tabela = new Hashtable<String, LinkedList<String>> ();
	}

	public boolean insere(String palavra, String documento) {
	    LinkedList<String> listaDocumentos = tabela.get(palavra);

	    if (listaDocumentos != null) {
	        if (!listaDocumentos.contains(documento)) {
	            listaDocumentos.add(documento);
	            return true;
	        }
	        return false;
	    } else {
	        LinkedList<String> novaListaDocumentos = new LinkedList<String>();
	        novaListaDocumentos.add(documento);
	        tabela.put(palavra, novaListaDocumentos);
	        return true;
	    }
	}


    public LinkedList<String> busca(String palavra) {
        return tabela.get(palavra);
    }

    @Override
    public String toString() {
        return tabela.toString();
    }

}