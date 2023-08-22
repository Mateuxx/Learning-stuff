package br.edu.ufam.icomp.lab_excecoes;

public class DistanciaEntrePontosExcedidaException extends RoverCaminhoException {
	private static final long serialVersionUID = 1L;

	
	public DistanciaEntrePontosExcedidaException () {
		super ( "Distância máxima entre duas coordenadas vizinhas excedida");
	}
	
	public DistanciaEntrePontosExcedidaException (String message) {
		super(message);
	}
}
	
	
