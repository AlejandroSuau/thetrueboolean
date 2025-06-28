#include "picosha2.h"

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

class Block {
public:
    std::size_t index_;
    std::string data_;
    std::string previous_hash_;
    std::string hash_;
    time_t timestamp_;
    std::size_t nonce_;

    Block(std::size_t index, std::string data, std::string previous_hash)
        : index_(index), data_(data), previous_hash_(previous_hash) {
        timestamp_ = std::time(nullptr);
        nonce_ = 0;
        hash_ = CalculateHash();
    }

    std::string CalculateHash() const {
        std::string to_hash = 
            std::to_string(index_) + data_ + previous_hash_ +
            std::to_string(timestamp_) + std::to_string(nonce_);
        return picosha2::hash256_hex_string(to_hash);
    }

    void MineBlock(int difficulty) {
        std::string target(difficulty, '0');
        while (hash_.substr(0, difficulty) != target) {
            ++nonce_;
            hash_ = CalculateHash();
        }
        std::cout << "Block mined! " << hash_ << std::endl;
    }
};

class BlockChain {
public:
    std::vector<Block> chain_;
    std::size_t difficulty_;

    BlockChain() {
        chain_.emplace_back(CreateGenesisBlock());
        difficulty_= 4;
    }

    Block CreateGenesisBlock() {
        return Block(0, "Genesis Block", "0");
    }

    Block GetLatestBlock() {
        return chain_.back();
    }

    void AddBlock(std::string data) {
        Block new_block{chain_.size() + 1, data, GetLatestBlock().hash_};
        new_block.MineBlock(difficulty_);
        chain_.push_back(new_block);
    }

    void PrintBlocks() const {
        std::stringstream ss;
        for (const auto& b : chain_) {
            ss << "-------------------- Block " << b.index_ << " --------------------\n"
               << "# Hash: " << b.hash_ << "\n"
               << "# Data: " << b.data_ << "\n"
               << "# Previous Hash: " << b.previous_hash_ << "\n"
               << "# Nonce: " << b.nonce_ << "\n"
               << "# Timestamp: " << std::ctime(&b.timestamp_) << ""
               << "------------------------------------------------------------";
        }

        std::cout << ss.str();
    }
};

int main() {
    BlockChain block_chain;

    std::cout << "Mining block 1 ..." << std::endl;
    block_chain.AddBlock("Bob envia 0.5BTC a Eustaquio ... Peter envia 1 BTC a Bob ...");

    std::cout << "Mining block 2 ..." << std::endl;
    block_chain.AddBlock("TheTrueBoolean envia 500 BTC a Sara ... Bob envia 3 BTC a Alejandro ...");

    std::cout << "\n\n#################### Listing BlockChain ####################\n";

    block_chain.PrintBlocks();
}
