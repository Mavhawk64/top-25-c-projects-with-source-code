use std::io;
use std::io::Write;
fn main() {
    let types: Vec<String> = vec!["rock", "paper", "scissors"]
        .iter()
        .map(|x| x.to_string())
        .collect();
    let rand_num = rand::random_range(0..3) as i8;
    print!("Choose rock, paper, or scissors: ");
    io::stdout().flush().expect("Failed to flush stdout");
    let mut user_choice = String::new();
    io::stdin()
        .read_line(&mut user_choice)
        .expect("Failed to read line");
    user_choice = user_choice.trim().to_string();
    println!("You chose: '{user_choice}'");
    println!("Computer chose: {}", types[rand_num as usize]);
    let user_choice_idx = match types.iter().position(|x| *x == user_choice) {
        None => -1 as i8,
        Some(ans) => ans as i8,
    };
    let winner = get_winner(user_choice_idx, rand_num);
    if winner == 0 {
        println!("It's a draw!");
    } else {
        println!("Player {winner} wins!");
    }
}

fn get_winner(a: i8, b: i8) -> i8 {
    if a == -1 {
        return 2;
    }
    return (3 - (b - a) % 3) % 3;
}
