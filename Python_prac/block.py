#a block in blockchain
class block:
    def __init__(self,index,transaction,timestamp):
        self.index=index
        self.transaction=transaction
        self.timestamp=timestamp