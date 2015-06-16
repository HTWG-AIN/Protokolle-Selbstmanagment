package aufgabe6;

import java.util.Iterator;
import java.util.NoSuchElementException;

public final class FachNotenListe implements Iterable<FachNote> {

	private Element head = null;

	// private ArrayList liste;

	public FachNotenListe() {
		// super();
		// liste = new ArrayList<FachNote>();
	}

	private static final class Element {
		private final Element next;
		private FachNote fachNote;

		public Element(final Element next, final FachNote fachNote) {
			this.next = next;
			this.fachNote = fachNote;
		}

	}

	public FachNotenListe einfuegen(FachNote f) {
		this.head = new Element(this.head, f);
		return this;
	}

	@Override
	public Iterator<FachNote> iterator() {
		return new Iterator<FachNote>() {
	
//	private static class Iter implements Iterator<FachNote>{
			private Element curr = FachNotenListe.this.head;
	
			@Override
			public boolean hasNext() {
				return this.curr != null;
			}

			@Override
			public FachNote next() {
				if (this.curr == null) {
					throw new NoSuchElementException();
				}
				Element e = this.curr;
				this.curr = this.curr.next;
				return e.fachNote;
			}

			public void remove() throws UnsupportedOperationException {
				throw new UnsupportedOperationException(
						"Operation is not supported");
			}

		};
	}

}
