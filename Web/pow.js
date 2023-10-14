class Blockchain {
    constructor() {
        this.chain = [this.createGenesisBlock()];

        // 난이도 설정
        this.difficulty = 4;
    }

    // 제네시스 블록 생성
    createGenesisBlock() {
        return new Block(0, "01/01/2023", "Genesis Block", "0");
    }

    // 가장 최근 블록 반환
    getLatestBlock() {
        return this.chain[this.chain.length - 1];
    }

    // 새로운 블록 추가
    addBlock(newBlock) {
        // 이전 블록의 해시를 현재 블록의 previousHash로 설정
        newBlock.previousHash = this.getLatestBlock().hash;
        
        // 새로운 블록의 작업 증명(mine) 수행
        newBlock.mineBlock(this.difficulty);

        // 체인에 새로운 블록 추가
        this.chain.push(newBlock);
    }

    // 블록체인의 유효성 검증
    isChainValid() {
        for (let i = 1; i < this.chain.length; i++) {  
            const currentBlock = this.chain[i];
            const previousBlock = this.chain[i - 1];

            // 현재 블록의 해시 값이 유효한지 검증
            if (currentBlock.hash !== currentBlock.calculateHash()) {
                return false;
            }

            // 현재 블록의 이전 해시 값과 이전 블록의 해시 값이 일치하는지 검증
            if (currentBlock.previousHash !== previousBlock.hash) {
                return false;
            }
        }

        return true;
    }
}
