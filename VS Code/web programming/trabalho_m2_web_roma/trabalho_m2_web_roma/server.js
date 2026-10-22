const express = require('express');
const app = express();
const PORTA = 3000;

let obras = [];
let proximoId = 1;

app.use(express.json());
app.use(express.static('public'));

app.get('/api/obras', (req, res) => {
    res.json(obras);
});

app.post('/api/obras', (req, res) => {
    const obra = req.body;
    obra.id = proximoId;
    proximoId++;
    obras.push(obra);
    res.status(201).json(obra);
});

app.delete('/api/obras/:id', (req, res) => {
    const id = Number(req.params.id);
    obras = obras.filter(obra => obra.id !== id);
    res.sendStatus(204);
});

app.listen(PORTA, () => {
    console.log(`Servidor aberto em http://localhost:${PORTA}`);
});
