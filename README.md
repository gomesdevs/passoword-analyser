# Password-analyser

 * Analyzes the strength of a given password
 * 
 * This function evaluates a password's strength based on several criteria:
 * - Length (8+ chars = +1 point, 12+ chars = +2 points)
 * - Presence of lowercase letters (+1 point)
 * - Presence of uppercase letters (+1 point)
 * - Presence of digits (+1 point)
 * - Presence of special characters (+1 point)
 * - Absence of common patterns like "password", "1234", etc. (+1 point)
 * 
 * The function prints a detailed analysis of the password strength to the console
 * and returns a string indicating the overall strength assessment.
 * 
 * @param password The password string to analyze
 * @return string "Strong" (6-7 points), "Moderate" (4-5 points), or "Weak" (0-3 points)
   
