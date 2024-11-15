import CIE.*;
import SEE.*;

class Main {
	public static void main(String xx[]){
		short i_i1[] = {45, 34, 32, 50, 50};
		short i_i2[] = {45, 41, 50, 50, 42};
		CIE.Internals i1 = new CIE.Internals("ABC", "1BM23CS305", 3, i_i1, i_i2);

		i1.display();
		System.out.println();

		short i_e[] = {89, 98, 90, 95, 95};

		SEE.Externals i2 = new SEE.Externals("ABC", "1BM23CS305", 3, i_e);

		i2.display(i1);

	}

}
