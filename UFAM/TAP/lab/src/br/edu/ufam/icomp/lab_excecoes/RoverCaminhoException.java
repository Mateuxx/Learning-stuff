package br.edu.ufam.icomp.lab_excecoes;

public class RoverCaminhoException extends RoverException {
	private static final long serialVersionUID = 1L;

	public RoverCaminhoException () {
		super ("Exceção geral de caminho do rover");
	}
	
	public RoverCaminhoException (String message) {
		super(message);
	}
}
