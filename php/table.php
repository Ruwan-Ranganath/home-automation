<?php
$servername = "localhost";
$username = "root";
$password = "secret2";
$dbname = "arduino";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

// sql to create table
$sql = "CREATE TABLE interlista (
id INT(11) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
ldrval VARCHAR(30) NOT NULL,
wtrlvl VARCHAR(30) NOT NULL,
humidi VARCHAR(30) NOT NULL,
tempt VARCHAR(30) NOT NULL,
pwrlvl VARCHAR(30) NOT NULL,
created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP

)";

if ($conn->query($sql) === TRUE) {
    echo "Table interlista created successfully";
} else {
    echo "Error creating table: " . $conn->error;
}

$conn->close();
?>
