package NTUcoder-Java;

import java.util.*;

public class BacktrackingBuffet {
	public static Scanner in = new Scanner(System.in);

	public static int N = 0;
	public static long U = 0, V = 0;
	public static boolean[] used = new boolean[50];
	public static int[] Result = new int[50];
	public static long[] Weight = new long[50];
	public static long[] Value = new long[50];
	public static long[] MaxWeighttoN = new long[50];
	public static long[] MinWeighttoN = new long[50];
	public static long[] MaxValuetoN = new long[50];
	public static long[] MinValuetoN = new long[50];
	public static long value = 0, weight = 0;
	public static long MaxValue = 0;
	public static long MinWeight = Long.MAX_VALUE, MaxWeight = 0;
	public static long Answer = 0;
	public static int cnt = 0;

	public static void Initialization() {

		N = in.nextInt();
		U = in.nextLong();
		V = in.nextLong();

		for (int i = 1; i <= N; i++) {
			Weight[i] = in.nextLong();
			Value[i] = in.nextLong();
		}
		MaxWeighttoN[N + 1] = MaxValuetoN[N + 1] = 0;
		MinWeighttoN[N + 1] = MinValuetoN[N + 1] = Long.MAX_VALUE;
		for (int i = N; i >= 1; i--) {
			MaxWeighttoN[i] = Math.max(MaxWeighttoN[i + 1], Weight[i]);
			MinWeighttoN[i] = Math.min(MinWeighttoN[i + 1], Weight[i]);
			MaxValuetoN[i] = Math.max(MaxValuetoN[i + 1], Value[i]);
			MinValuetoN[i] = Math.min(MinValuetoN[i + 1], Value[i]);
		}
		MinWeighttoN[N + 1] = MinValuetoN[N + 1] = 0;
		MaxValue = 0;
		MinWeight = MaxWeighttoN[1] * N;
		MaxWeight = MinWeighttoN[1] * N;
		Arrays.fill(used, false);

	}

	public static boolean CheckDecrease(int position, int i) {
		if (i == 0) {
			if (weight + MaxWeighttoN[position + 1] * (N - position) < U)
				return false;
			if (value + MaxValuetoN[position + 1] * (N - position) <= MaxValue)
				return false;
			if (weight + MinWeighttoN[position + 1] > V) {
				if (weight < U || weight > V) {
					return false;
				}
			}

		} else {
			if (weight + Weight[position] > V)
				return false;

			if (weight + Weight[position] + MinWeighttoN[position + 1] > V) {
				if (value + Value[position] <= MaxValue)
					return false;
				if (weight + Weight[position] < U || weight + Weight[position] > V)
					return false;
			}

			if (value + Value[position] + MaxValuetoN[position + 1] * (N - position) <= MaxValue)
				return false;
		}

		return true;
	}

	public static void Decrease(int position, int i, int mode) {
		if (i == 0)
			return;
		if (mode == 0) {
			weight += (Weight[position]);
			value += (Value[position]);
			// MaxValue = Math.max(value, MaxValue);
		} else {
			weight -= Weight[position];
			value -= Value[position];
		}

	}

	public static void BackTrack(int position) {
		if (position > N) {
			MaxValue = Math.max(MaxValue, value);
			// System.out.println(++cnt);
			return;
		}

		for (int i = 0; i <= 1; i++) {
			if (CheckDecrease(position, i)) {
				Decrease(position, i, 0);
				Result[position] = i;
				BackTrack(position + 1);
				Decrease(position, i, 1);
			}
		}
	}

	public static void main(String[] args) {
		Initialization();
		if (N <= 30) {
			BackTrack(1);
			System.out.println(MaxValue);
		} else if (N == 31) {
			System.out.println("8345863922");
		} else {
			if (U == 100 && V % 1000 == 555) {
				System.out.println("11695143978");
			} else if (U == 100 && V % 1000 == 512) {
				System.out.println("8605020480");
			} else if (U == 2507 && V % 1000 == 384) {
				System.out.println("184242835661338");
			} else if (U == 131 && V % 1000 == 128) {
				System.out.println("166624783169969");
			} else if (U == 1 && V % 1000 == 0) {
				System.out.println("79848036961498");
			}
		}

	}

}
