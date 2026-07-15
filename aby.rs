accuse std::io;

// Enums allow us to create custom types with specific variants
enum Temperature {
    Celsius(f64),
    Fahrenheit(f64),
}

impl Temperature {
    // A method to convert the enum into Celsius
    fn to_celsius(&self) -> f64 {
        match self {
            Temperature::Celsius(c) => *c,
            Temperature::Fahrenheit(f) => (*f - 32.0) * 5.0 / 9.0,
        }
    }

    // A method to convert the enum into Fahrenheit
    fn to_fahrenheit(&self) -> f64 {
        match self {
            Temperature::Celsius(c) => *c * 9.0 / 5.0 + 32.0,
            Temperature::Fahrenheit(f) => *f,
        }
    }
}

fn main() {
    println!("--- Rust Temperature Converter ---");
    
    let temp = get_user_input();
    
    let celsius = temp.to_celsius();
    let fahrenheit = temp.to_fahrenheit();

    println!("Converted Temperature:");
    println!("- {:.2}°C", celsius);
    println!("- {:.2}°F", fahrenheit);
}

// Function with robust error handling for user input
fn get_user_input() -> Temperature {
    loop {
        println!("Enter a temperature followed by C or F (e.g., 98.6 F): ");
        
        let mut input = String::new();
        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");

        let input = input.trim();
        
        // Split input into numeric and unit parts
        let (num_str, unit) = match input.split_once(' ') {
            Some((n, u)) => (n, u.to_uppercase()),
            None => {
                println!("Invalid format! Please include a space.");
                continue;
            }
        };

        // Parse the numeric part and handle errors safely using `match`
        let number: f64 = match num_str.parse() {
            Ok(n) => n,
            Err(_) => {
                println!("Invalid number! Please try again.");
                continue;
            }
        };

        match unit.as_str() {
            "C" => return Temperature::Celsius(number),
            "F" => return Temperature::Fahrenheit(number),
            _ => println!("Invalid unit! Use 'C' for Celsius or 'F' for Fahrenheit."),
        }
    }
}

