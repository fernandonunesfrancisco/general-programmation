const formulario = document.getElementById('formObra');
const mensagensErro = document.getElementById('mensagensErro');
const tabelaObras = document.getElementById('tabelaObras');
const detalhamentoSelecionado = document.getElementById('detalhamentoSelecionado');

function limparErros() {
    mensagensErro.innerHTML = '';
    document.querySelectorAll('.erro').forEach(campo => {
        campo.classList.remove('erro');
    });
}

function mostrarErro(campo, mensagem) {
    campo.classList.add('erro');
    const item = document.createElement('li');
    item.textContent = mensagem;
    mensagensErro.appendChild(item);
}

function validarFormulario() {
    limparErros();

    const nome = document.getElementById('nome');
    const autor = document.getElementById('autor');
    const ano = document.getElementById('ano');
    const periodo = document.getElementById('periodo');
    const tipo = document.getElementById('tipo');

    if (nome.value.trim().length === 0) {
        mostrarErro(nome, 'Informe o nome da obra.');
    } else if (nome.value.trim().length < 6) {
        mostrarErro(nome, 'O nome da obra deve ter pelo menos 6 caracteres.');
    }

    if (autor.value.trim().length === 0) {
        mostrarErro(autor, 'Informe o autor.');
    } else if (autor.value.trim().length < 10) {
        mostrarErro(autor, 'O autor deve ter pelo menos 10 caracteres.');
    }

    if (ano.value.trim() === '') {
        mostrarErro(ano, 'Informe o ano da obra.');
    } else if (!/^\d{1,4}$/.test(ano.value.trim())) {
        mostrarErro(ano, 'O ano deve ser um número de até 4 algarismos.');
    }

    if (periodo.value === '') {
        mostrarErro(periodo, 'Selecione o período da obra.');
    }

    if (tipo.value === '') {
        mostrarErro(tipo, 'Selecione o tipo da obra.');
    }

    return mensagensErro.children.length === 0;
}

async function carregarObras() {
    const resposta = await fetch('/api/obras');
    const obras = await resposta.json();
    tabelaObras.innerHTML = '';

    obras.forEach(obra => {
        const linha = document.createElement('tr');

        [obra.nome, obra.autor, obra.ano, obra.periodo, obra.tipo].forEach(texto => {
            const celula = document.createElement('td');
            celula.textContent = texto;
            linha.appendChild(celula);
        });

        const celulaExcluir = document.createElement('td');
        const botaoExcluir = document.createElement('button');
        botaoExcluir.textContent = 'Excluir';
        botaoExcluir.type = 'button';
        celulaExcluir.appendChild(botaoExcluir);
        linha.appendChild(celulaExcluir);

        linha.addEventListener('click', () => {
            detalhamentoSelecionado.textContent = obra.detalhamento || 'Esta obra não possui detalhamento.';
        });

        botaoExcluir.addEventListener('click', async (evento) => {
            evento.stopPropagation();
            if (confirm('Deseja realmente excluir esta obra?')) {
                await fetch('/api/obras/' + obra.id, { method: 'DELETE' });
                carregarObras();
                detalhamentoSelecionado.textContent = 'Nenhuma obra selecionada.';
            }
        });

        tabelaObras.appendChild(linha);
    });
}

formulario.addEventListener('submit', async (evento) => {
    evento.preventDefault();

    if (!validarFormulario()) {
        return;
    }

    const obra = {
        nome: document.getElementById('nome').value.trim(),
        autor: document.getElementById('autor').value.trim(),
        ano: document.getElementById('ano').value.trim(),
        periodo: document.getElementById('periodo').value,
        tipo: document.getElementById('tipo').value,
        detalhamento: document.getElementById('detalhamento').value.trim()
    };

    await fetch('/api/obras', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(obra)
    });

    formulario.reset();
    limparErros();
    detalhamentoSelecionado.textContent = 'Clique numa obra para ver seu detalhamento.';
    carregarObras();
});

carregarObras();
