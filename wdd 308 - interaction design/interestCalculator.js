function calculateRate(principle, interestRate, time) {
    var principle;
    principle = (parseFloat(document.getElementById('pInput').value)).toFixed(2);
    var interestRate;
    interestRate = parseFloat(document.getElementById('irInput').value);
    var time;
    time = parseFloat(document.getElementById('tiInput').value);


    var grandTotal = (principle * (1 + ((interestRate / 100) * time))).toFixed(2);

    var interest = (grandTotal - principle).toFixed(2);

    document.getElementById('principle').innerHTML = principle;
    document.getElementById('growthRate').innerHTML = interestRate;
    document.getElementById('time').innerHTML = time;

    document.getElementById('interest').innerHTML = interest;
    document.getElementById('grandTotal').innerHTML = grandTotal;
}