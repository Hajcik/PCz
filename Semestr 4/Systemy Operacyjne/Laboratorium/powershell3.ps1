Add-Type -AssemblyName System.Windows.Forms
$Okno.FormBorderStyle =[System.Windows.Forms.FormBorderStyle]::FixedSingle
$Okno = New-Object System.Windows.Forms.Form
$Okno.Text ="Laboratorium 3.1."
$Okno.Width = 800
$Okno.Height = 600

$Kolor_Button = New-Object System.Windows.Forms.Button
$Kolor_Button.Location = New-Object System.Drawing.Size (100, 200)
$Kolor_Button.Text = "KOLOR"

$Kolor_Dialog = New-Object System.Windows.Forms.ColorDialog

$Kolor_Button.Add_Click(
    {
 if($Kolor_Dialog.ShowDialog() -eq [System.Windows.Forms.DialogResult]::OK)
        { 
            $Okno.BackColor = $Kolor_Dialog.Color
        }
    }
)

$Text1_Button = New-Object System.Windows.Forms.TextBox
$Text1_Button.Location = New-Object System.Drawing.Size (100, 100)
$Text2_Button = New-Object System.Windows.Forms.TextBox
$Text2_Button.Location = New-Object System.Drawing.Size (250, 100)

$Suma_Button = New-Object System.Windows.Forms.Button
$Suma_Button.Location = New-Object System.Drawing.Size (100, 250)
$Suma_Button.Text = "SUMA"
$Suma_Button.Add_Click({
            $0_Label.Text = Suma
    })

$Odejmowanie_Button = New-Object System.Windows.Forms.Button
$Odejmowanie_Button.Location = New-Object System.Drawing.Size (100, 300)
$Odejmowanie_Button.Text ="RÓŻNICA"
$Odejmowanie_Button.Add_Click({
            $0_Label.Text = Roznica
    })

$Mnozenie_Button = New-Object System.Windows.Forms.Button
$Mnozenie_Button.Location = New-Object System.Drawing.Size (100, 350)
$Mnozenie_Button.Text = "MNOŻENIE"
$Mnozenie_Button.Add_Click({
            $0_Label.Text = Mnozenie
     })

$Dzielenie_Button = New-Object System.Windows.Forms.Button
$Dzielenie_Button.Location = New-Object System.Drawing.Size (100, 400)
$Dzielenie_Button.Text = "DZIELENIE"
$Dzielenie_Button.Add_Click({
    Try {
            $0_Label.Text = Dzielenie 
        } Catch {
            $0_Label.Text = "ERROR"
                }
    })
 
$Czcionka_Button = New-Object System.Windows.Forms.Button
$Czcionka_Button.Location = New-Object System.Drawing.Size(250, 330)
$Czcionka_Button.Text = "CZCIONKA"

$Czcionka_Dialog = New-Object System.Windows.Forms.FontDialog
$Czcionka_Dialog.ShowColor = $True

$Czcionka_Button.Add_Click({
    if($Czcionka_Dialog.ShowDialog() -eq [System.Windows.Forms.DialogResult]::OK){
        $0_Label.Font = $Czcionka_Dialog.Font
        $0_Label.ForeColor = $Czcionka_Dialog.Color
        }
    })

$0_Label = New-Object System.Windows.Forms.Label
$0_Label.Location = New-Object System.Drawing.Size (300, 300)
$0_Label.Width = 200
$0_Label.Text = "0"

$Wynik_Label = New-Object System.Windows.Forms.Label
$Wynik_Label.Location = New-Object System.Drawing.Size (260, 300)
$Wynik_Label.Width = 200
$Wynik_Label.Text= "Wynik: "

Function Suma {
    $x = [System.Convert]::ToInt32($Text1_Button.Text)
    $y = [System.Convert]::ToInt32($Text2_Button.Text)
        return $x + $y
}

Function Roznica {
    $x = [System.Convert]::ToInt32($Text1_Button.Text)
    $y = [System.Convert]::ToInt32($Text2_Button.Text)
        return $x - $y
}

Function Mnozenie {
    $x = [System.Convert]::ToInt32($Text1_Button.Text)
    $y = [System.Convert]::ToInt32($Text2_Button.Text)
        return $x * $y
}

Function Dzielenie {
    $x = [System.Convert]::ToInt32($Text1_Button.Text)
    $y = [System.Convert]::ToInt32($Text2_Button.Text)
        return $x / $y
}


$Okno.Controls.Add($Suma_Button)
$Okno.Controls.Add($Odejmowanie_Button)
$Okno.Controls.Add($Mnozenie_Button)
$Okno.Controls.Add($Dzielenie_Button)
$Okno.Controls.Add($Text1_Button)
$okno.Controls.Add($Text2_Button)
$Okno.Controls.Add($Kolor_button)
$Okno.Controls.Add($0_Label)
$Okno.Controls.Add($Wynik_Label)
$Okno.Controls.Add($Czcionka_Button)

$Okno.ShowDialog()
