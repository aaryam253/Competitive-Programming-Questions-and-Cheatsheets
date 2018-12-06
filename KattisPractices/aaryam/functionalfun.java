import java.util.*;
public class functionalFun {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		boolean inject = true, surj = true, function = true;
		
		String[] domain = new String[ 0 ], codomain = new String[ 0 ];
		HashMap<String, String> mappings = new HashMap<String, String>();
		
		while (scan.hasNextLine()) {
			StringTokenizer line = new StringTokenizer( scan.nextLine() );
			String firstinstance = line.nextToken();
			
			if (firstinstance.equals("domain")) {
				inject = true; surj = true; function = true;
				domain = new String[ line.countTokens() ];
				int numDomain = line.countTokens();
				for ( int i = 0; i < numDomain; i++ ) domain[i] = line.nextToken();
			}
			else if (firstinstance.equals("codomain")) {
				codomain = new String[ line.countTokens() ];
				
				int numCodomain = line.countTokens();
				for ( int i = 0; i < numCodomain; i++ ) codomain[i] = line.nextToken();
			}
			else{
				if (line.countTokens() == 0) {
					int steps;
					steps = Integer.parseInt( firstinstance );
					mappings = new HashMap<String, String>();

					for (int i = 0; i < steps; i++) {
						StringTokenizer lines = new StringTokenizer( scan.nextLine() );
						firstinstance = lines.nextToken();

						lines.nextToken();
						String mappedvalue = lines.nextToken();
					
						if (mappings.containsKey(firstinstance)) function = false;
					
						if (mappings.containsValue(mappedvalue)) inject = false;
				
						mappings.put(firstinstance, mappedvalue);
					}

					for (int i = 0; i < codomain.length; i++) {
						if (!mappings.containsValue(codomain[i])) {
							surj = false; break;
						}
					}
					if (function){
						if (inject){
							if (surj) System.out.println("bijective");
							else System.out.println("injective");
						}
						else {
							if (surj) System.out.println("surjective");
							else System.out.println("neither injective nor surjective");
						}
					}
					else System.out.println("not a function");
				}
			}
		}
		scan.close();
	}
}
