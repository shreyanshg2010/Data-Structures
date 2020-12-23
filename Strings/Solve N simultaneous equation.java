Question-
You are given a series of arithmetic equation as a string such as
y = x + 1
5 = x + 3
10 = y + z + 2
The equation uses addition only and are seperated by new lines. Return a mapping of all variables to their values. If its not possible return null.
In this example you should return 
{
x:2,
y:3,
z:5
}

Code - 

import java.util.*;
import java.io.*;
public class Main
{
	private static final int COUNT = 10;
	private static final int MIN = -1000000;
	private static final String input = "y = x + 1\n5 = x + 3\n10 = z + y + 2\n a=0+9";
	private static Map<String, Integer> inputVariables = new HashMap<>();
	private static Stack<String> lineStack = new Stack<>();

	public static void main(String[] args) {
		String[] lines = input.split("\n");
		String[] sides = new String[100];
		String line = new String();

		for (int i = 0; i < lines.length; i++) {
			line = lines[i];
			lineStack.add(line);
		}

		int i = 0;
		while (i < lineStack.size()) {

			line = lineStack.get(i);
			sides = line.split("=");
			if (checkLines(sides) == false) {
				i = i + 1;
				continue;
			} else {
				lineStack.remove(i);
				i = 0;
				continue;
			}

		} // end i

		if (lineStack.isEmpty()) {
			System.out.println("success to solve");
		} else {
			System.out.println("Fail to solve");
		}

		System.out.println("unsolved statement : " + lineStack);
		System.out.println("final values : " + inputVariables);
	}

	private static Boolean checkLines(String[] sides) {
		Boolean retVal = false;

		String[] variables = new String[COUNT];

		Integer[] getNumber = new Integer[COUNT];
		String[] getVariables = new String[COUNT];

		int intCount = 0;
		int varCount = 0;

		for (int j = 0; j < sides.length; j++) {

			if (j == 0)
				continue;
			String temp = sides[j].toString().trim();
			for (int k = 0, count = 0; k < temp.length(); k++) {
				switch (temp.charAt(k)) {
				case '+':
					break;
				case ' ':
					break;
				default:
					variables[count] = String.valueOf(temp.charAt(k));
					count++;
					break;
				}

			} // end for k

			for (int i = 0; i < variables.length; i++) {
				if (variables[i] == null)
					continue;
				String tempChar = variables[i].toString().trim();
				if (checkDigit(tempChar)) {
					// number
					getNumber[intCount] = Integer.valueOf(tempChar);
					intCount++;
				} else {
					// variable
					if (checkVariables(tempChar) != MIN) {
						getNumber[intCount] = checkVariables(tempChar);
						intCount++;
					} else {
						getVariables[varCount] = tempChar;
						varCount++;
					}
				}
			}
		} // end for j

		String tempChar = sides[0].toString().trim();
		char getLeftVariable = tempChar.charAt(0);
		if (Character.isDigit(getLeftVariable)) {
			// number
			if (varCount > 1) {
				retVal = false;
				return retVal;
			} else {
				calculate(tempChar, getNumber, getVariables);
				retVal = true;
				return retVal;
			}

		} else {
			if (varCount > 0) {
				retVal = false;
				return retVal;
			} else {
				calculate(tempChar, getNumber, getVariables);
				retVal = true;
				return retVal;
			}
		}
	}

	private static void calculate(String left, Integer[] getNumber, String[] getVariables) {
		int countedVariable = 0;

		if (checkDigit(left)) {
			countedVariable = Integer.valueOf(left);
			for (int i = 0; i < getNumber.length; i++) {
				if (getNumber[i] == null)
					continue;
				countedVariable = countedVariable - getNumber[i];
			}
			inputVariables.put(getVariables[0], countedVariable);
		} else {
			for (int i = 0; i < getNumber.length; i++) {
				if (getNumber[i] == null)
					continue;
				countedVariable += getNumber[i];
			}
			inputVariables.put(left, countedVariable);
		}
	}

	private static Boolean checkDigit(String getStr) {
		Boolean retVal = false;

		String temp = getStr.trim();
		char getCh = temp.charAt(0);

		if (Character.isDigit(getCh))
			retVal = true;

		return retVal;
	}

	private static int checkVariables(String variable) {
		int retVal = MIN;

		if (!inputVariables.isEmpty()) {
			if (inputVariables.containsKey(variable)) {
				retVal = inputVariables.get(variable);
			}
		}
		return retVal;
	}
}
