public class Empregado {
    private String primeiroNome;
    private String sobrenome;
    private double salarioMensal;
    
    public Empregado(String primeiroNome, String sobrenome, double salarioMensal) {
        this.primeiroNome = primeiroNome;
        this.sobrenome = sobrenome;
        if (salarioMensal > 0) {
            this.salarioMensal = salarioMensal;
        } else {
            this.salarioMensal = 0.0;
        }
    }
    
    public String getPrimeiroNome() {
        return primeiroNome;
    }
    
    public void setPrimeiroNome(String primeiroNome) {
        this.primeiroNome = primeiroNome;
    }
    
    public String getSobrenome() {
        return sobrenome;
    }
    
    public void setSobrenome(String sobrenome) {
        this.sobrenome = sobrenome;
    }
    
    public double getSalarioMensal() {
        return salarioMensal;
    }
    
    public void setSalarioMensal(double salarioMensal) {
        if (salarioMensal > 0) {
            this.salarioMensal = salarioMensal;
        } else {
            this.salarioMensal = 0.0;
        }
    }
    
    public double getSalarioAnual() {
        return salarioMensal * 12;
    }
    
    public void aplicarAumento(double percentual) {
        salarioMensal += salarioMensal * (percentual / 100);
    }



    public static void main(String[] args) {
        Empregado empregado1 = new Empregado("Mateus", "Mota", 9500.0);
        Empregado empregado1 = new Empregado("Maria", "Luiza", 4000.0);

        System.out.println("Salário anual do empregado 1: " + empregado1.salarioMensal * 12);
        System.out.println("Salário anual do empregado 2: " + empregado2.salarioMensal * 12);
        empregado1.aplicarAumento(10);
        empregado2.aplicarAumento(10);
        System.out.println(" Apos aumento Novo salário anual do empregado 1: " + empregado1.salarioMensal * 12);
        System.out.println("Apos aumento  Novo salário anual do empregado 2: " + empregado2.salarioMensal * 12);
    }
}

