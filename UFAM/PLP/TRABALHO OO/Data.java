import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Data {
    private int dia;
    private int mes;
    private int ano;

    public Data(int dia, int mes, int ano) {
        if (validarData(dia, mes, ano)) {
            this.dia = dia;
            this.mes = mes;
            this.ano = ano;
        } else {
            throw new IllegalArgumentException("Data inválida!");
        }
    }

    public Data() {
        LocalDate dataAtual = LocalDate.now();
        this.dia = dataAtual.getDayOfMonth();
        this.mes = dataAtual.getMonthValue();
        this.ano = dataAtual.getYear();
    }

    public int getDia() {
        return dia;
    }

    public void setDia(int dia) {
        if (validarData(dia, mes, ano)) {
            this.dia = dia;
        } else {
            throw new IllegalArgumentException("Dia inválido!");
        }
    }

    public int getMes() {
        return mes;
    }

    public void setMes(int mes) {
        if (validarData(dia, mes, ano)) {
            this.mes = mes;
        } else {
            throw new IllegalArgumentException("Mês inválido!");
        }
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        if (validarData(dia, mes, ano)) {
            this.ano = ano;
        } else {
            throw new IllegalArgumentException("Ano inválido!");
        }
    }

    public void avancarDia() {
        dia++;
        if (!validarData(dia, mes, ano)) {
            dia = 1;
            mes++;
            if (!validarData(dia, mes, ano)) {
                mes = 1;
                ano++;
            }
        }
    }

    @Override
    public String toString() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate data = LocalDate.of(ano, mes, dia);
        return data.format(formatter);
    }

    private boolean validarData(int dia, int mes, int ano) {
        if (ano >= 0 && mes >= 1 && mes <= 12 && dia >= 1) {
            int ultimoDiaDoMes = LocalDate.of(ano, mes, 1).lengthOfMonth();
            return dia <= ultimoDiaDoMes;
        }
        return false;
    }

    public static void main(String[] args) {
        Data data1 = new Data(06, 8, 2000);
        System.out.println( data1);
        data1.avancarDia();
        System.out.println("Data 1 depois de um dia: " + data1);
       
        
    }
}

    
