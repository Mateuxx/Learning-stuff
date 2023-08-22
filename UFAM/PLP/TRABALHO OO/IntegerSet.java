import java.util.Arrays;

public class IntegerSet {
    private boolean[] conjunto;
    private int limiteSuperior;

    public IntegerSet(int limiteSuperior) {
        if (limiteSuperior >= 0) {
            this.limiteSuperior = limiteSuperior;
            conjunto = new boolean[limiteSuperior + 1];
        } else {
            throw new IllegalArgumentException("Limite superior inválido!");
        }
    }

    public void inserirElemento(int elemento) {
        if (elemento >= 0 && elemento <= limiteSuperior) {
            conjunto[elemento] = true;
        } else {
            throw new IllegalArgumentException("Elemento inválido!");
        }
    }

    public void excluirElemento(int elemento) {
        if (elemento >= 0 && elemento <= limiteSuperior) {
            conjunto[elemento] = false;
        } else {
            throw new IllegalArgumentException("Elemento inválido!");
        }
    }

    public IntegerSet uniao(IntegerSet outroConjunto) {
        if (limiteSuperior != outroConjunto.limiteSuperior) {
            throw new IllegalArgumentException("limites superiores diferentes!");
        }

        IntegerSet uniao = new IntegerSet(limiteSuperior);
        for (int i = 0; i <= limiteSuperior; i++) {
            uniao.conjunto[i] = conjunto[i] || outroConjunto.conjunto[i];
        }
        return uniao;
    }

    public IntegerSet intersecao(IntegerSet outroConjunto) {
        if (limiteSuperior != outroConjunto.limiteSuperior) {
            throw new IllegalArgumentException("limites superiores diferentes!");
        }

        IntegerSet intersecao = new IntegerSet(limiteSuperior);
        for (int i = 0; i <= limiteSuperior; i++) {
            intersecao.conjunto[i] = conjunto[i] && outroConjunto.conjunto[i];
        }
        return intersecao;
    }

    public IntegerSet diferenca(IntegerSet outroConjunto) {
        if (limiteSuperior != outroConjunto.limiteSuperior) {
            throw new IllegalArgumentException("limites superiores diferentes!");
        }

        IntegerSet diferenca = new IntegerSet(limiteSuperior);
        for (int i = 0; i <= limiteSuperior; i++) {
            diferenca.conjunto[i] = conjunto[i] && !outroConjunto.conjunto[i];
        }
        return diferenca;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("{ ");
        for (int i = 0; i <= limiteSuperior; i++) {
            if (conjunto[i]) {
                sb.append(i).append(" ");
            }
        }
        sb.append("}");
        return sb.toString();
    }

    public static void main(String[] args) {
        IntegerSet conjunto1 = new IntegerSet(10);
        conjunto1.inserirElemento(4);
        conjunto1.inserirElemento(6);
        conjunto1.inserirElemento(8);

        System.out.println("Conjunto 1: " + conjunto1);
       
}
}