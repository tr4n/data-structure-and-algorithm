package NTUcoder-Java;

import java.util.*;

public class EightQueen {
	public static Scanner in = new Scanner(System.in);

	public static int X0, Y0;
	public static int[] Result = new int[100];
	public static int X = 1, Y = 1;
	public static boolean[] CrossOne = new boolean[300];
	public static boolean[] CrossTwo = new boolean[300];
	public static boolean[] Row = new boolean[100];
	public static boolean OK = false;

	public static void Initialization() {

		X0 = in.nextInt();
		Y0 = in.nextInt();

		Arrays.fill(CrossOne, false);
		Arrays.fill(CrossTwo, false);
		Arrays.fill(Row, false);
		CrossOne[100 + X0 - Y0] = CrossTwo[100 + X0 + Y0] = true;
		Row[Y0] = true;
		Result[X0] = Y0;

	}

	public static void Process() {
		OK = true;
		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				if (j != Result[i]) {
					System.out.print(". ");
				} else {
					System.out.print("w ");
				}
			}
			System.out.println();
		}

	}

	public static boolean CheckDecrease(int position, int i) {

		if (Row[i])
			return false;
		if (CrossOne[100 + position - i])
			return false;
		if (CrossTwo[100 + position + i])
			return false;
		// System.out.println((position - i ) + " " + (position + i));

		return true;
	}

	public static void Decrease(int position, int i, int mode) {

		if (mode == 0) {
			CrossOne[position - i + 100] = true;
			CrossTwo[position + i + 100] = true;
			Row[i] = true;
		} else {
			Row[i] = false;
			CrossOne[position - i + 100] = false;
			CrossTwo[position + i + 100] = false;
		}
	}

	public static void BackTrack(int position) {
		if (OK)
			return;
		if (position > 8) {
			Process();
			return;
		}
		if (position == X0)
			BackTrack(position + 1);
		else
			for (int i = 1; i <= 8; i++) {
				if (!CheckDecrease(position, i))
					continue;
				Decrease(position, i, 0);
				Result[position] = i;
				BackTrack(position + 1);
				Decrease(position, i, 1);
			}

	}

	public static void main(String[] args) {
		Initialization();
		BackTrack(1);
		if (!OK)
			System.out.println(-1);

	}

}
